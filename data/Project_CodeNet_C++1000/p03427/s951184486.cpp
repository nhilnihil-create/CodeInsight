#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;

int main(){
    string n;
    cin>>n;

    int ans=0;

    if(n.size()==1){
        cout<<n<<endl;
    }

    else {
        bool jdg=true;
        rep2(i,1,n.size()-1){
            if(n[i]!='9'){
                jdg=false;
                break;
            }
        }

        if(jdg) ans=(n[0]-'0')+9*(n.size()-1);
        else ans=(n[0]-'1')+9*(n.size()-1);

        cout<<ans<<endl;
    }
}
