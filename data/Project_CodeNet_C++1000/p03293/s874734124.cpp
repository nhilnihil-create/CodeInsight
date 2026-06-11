#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'

int main(){
    string s, t;
    cin >> s >> t;
    for(int i=0; i<=(int)s.length(); ++i){
        rotate(s.begin(), s.begin()+1, s.end());

        if(s==t){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
