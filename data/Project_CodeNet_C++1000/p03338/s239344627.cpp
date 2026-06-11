#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    string sl;
    string sr;

    int ans = 0;
    int cnt = 0;
    for(int i=1;i<n;i++){
        cnt = 0;
        sl = s.substr(0,i);
        sr = s.substr(i);
        //cout << sl << endl;
        //cout << sr << endl;

        for(char c = 'a';c <= 'z';c++){
            bool left = false,right = false;
            for(int j=0;j<sl.size();j++){
                if(sl[j] == c) {left = true;}
            }
            for(int j=0;j<sr.size();j++){
                if(sr[j] == c) right = true;
            }
            if(left&&right){cnt++;}
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
}