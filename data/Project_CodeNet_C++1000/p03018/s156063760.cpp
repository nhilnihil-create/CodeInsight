#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    string s;
    cin >> s;
    ll N = s.size();
    vector<char> ss;
    rep(i,N-1){
        if(s[i] == 'B' && s[i+1] == 'C'){
            ss.push_back('D');
            i++;
            continue;
        }
        ss.push_back(s[i]);
    }
    if(ss.size() > 0){
        if(ss[ss.size()-1] != 'D'){
            ss.push_back(s[N-1]);
        }
    }
    ll M = ss.size();
    ll cnt = 0, tmp = 0;
    bool flagA = false;
    /*rep(i,ss.size()){
        cout << ss[i];
    }
    cout << endl;*/
    rep(i,M){
        if(ss[i] == 'A'){
            flagA = true;
            tmp++;
            continue;
        }else if(ss[i] == 'D' && flagA){
            cnt += tmp;
        }else{
            flagA = false;
            tmp = 0;
        }
    }
    cout << cnt << endl;
    //ll cnt = 0;
    /*
    bool flag = true;;
    while(flag){
        flag = false;
        rep(i,N-2){
            if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
                s[i] = 'B';
                s[i+1] = 'C';
                s[i+2] = 'A';
                flag = true;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    */
}
