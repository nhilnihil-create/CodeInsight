#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    string s,t; cin >> s >> t;
    int sl=s.length();
    int tl=t.length();

    vector<vector<int> > num(26);
    rep(i,tl) num[t[i]-'a'].push_back(i);
    rep(i,26){
        if(num[i].size()<=1) continue;
        char f=s[num[i][0]];
        rep(j,num[i].size()-1){
            if(f!=s[num[i][j+1]]){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    vector<vector<int> > num2(26);
    rep(i,sl) num2[s[i]-'a'].push_back(i);
    rep(i,26){
        if(num2[i].size()<=1) continue;
        char f=t[num2[i][0]];
        rep(j,num2[i].size()-1){
            if(f!=t[num2[i][j+1]]){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
