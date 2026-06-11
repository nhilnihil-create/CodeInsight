#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    string S;cin>>S;
    int N=S.size();
    
    if(N%2){
        bool ok=true;
        int to=1;
        for(int i=0;i<(N-1)/2;i++){
            if(S[i]!=S[N-2-i]) ok=false;
            if(S[i]=='1') to=i+1;
        }
        if(S[0]=='0') ok=false;
        if(S[N-1]=='1') ok=false;
        if(!ok) cout<<-1<<endl;
        else{
            int before=2,now=3;
            cout<<"1 2"<<endl;
            for(int i=1;i<to;i++){
                if(S[i]=='1'){
                    cout<<before<<" "<<now<<endl;
                    before=now;
                    now++;
                }else{
                    cout<<before<<" "<<now<<endl;
                    now++;
                }
            }
            for(int i=to;i<N-1;i++){
                cout<<before<<" "<<now<<endl;
                now++;
            }
        }
    }else{
        bool ok=true;
        int to=1;
        for(int i=0;i<=(N-1)/2;i++){
            if(S[i]!=S[N-2-i]) ok=false;
            if(S[i]=='1') to=i+1;
        }
        if(S[0]=='0') ok=false;
        if(S[N-1]=='1') ok=false;
        if(!ok) cout<<-1<<endl;
        else{
            int before=2,now=3;
            cout<<"1 2"<<endl;
            for(int i=1;i<to;i++){
                if(S[i]=='1'){
                    cout<<before<<" "<<now<<endl;
                    before=now;
                    now++;
                }else{
                    cout<<before<<" "<<now<<endl;
                    now++;
                }
            }
            for(int i=to;i<N-1;i++){
                cout<<before<<" "<<now<<endl;
                now++;
            }
        }
    }
    
}

