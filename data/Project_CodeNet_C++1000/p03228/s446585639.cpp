#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
        ll a,b,k;
        cin>>a>>b>>k;
        ll tmp=a,res=b;
        bool ok=true;
        for(int i=0;i<k;i++){
                if(tmp%2){
                        tmp--;
                        res+=tmp/2;
                        tmp/=2;
                }else{
                        res+=tmp/2;
                        tmp/=2;
                }
                swap(tmp,res);
                if(ok)ok=false;
                else ok=true;
        }
        if(ok)cout<<tmp<<" "<<res<<endl;
        else cout<<res<<" "<<tmp<<endl;
        return 0;
}
