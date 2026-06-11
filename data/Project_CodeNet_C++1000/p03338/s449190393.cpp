#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for(int i=0; i<n-1; ++i){
        string a= s.substr(0, i+1);
        string b= s.substr(i+1);

        set<char> s1(a.begin(), a.end());
        set<char> s2(b.begin(), b.end());

        // cout << a << "    " << b << endl;

        // for(auto x:s1)
        //     cout << x;
        //     cout << "      ";
        // for(auto x:s2)
        //     cout << x;
        // cout << endl << endl << endl;

        int count=0;
        for(int j=0; j<s1.size(); ++j){
            auto el = s1.begin();
            advance(el, j);
            if(binary_search(s2.begin(), s2.end(), *el))
                count++;
        }
        ans = max(ans, count);
    }
    cout << ans;
}
