#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    string s; cin >> s;
    int ans=0;
    int i=0;
    int j=s.size()-1;
    while(true){
        if(i>=j) break;
        if(s[i]==s[j]){
            i++; j--;
        }else{
            if(s[i]=='x'&&s[j]!='x'){
                i++;
                ans++;
            }else if(s[i]!='x'&&s[j]=='x'){
                j--;
                ans++;
            }else{
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
}