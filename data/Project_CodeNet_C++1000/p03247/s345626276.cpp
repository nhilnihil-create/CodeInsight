#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long int a,b,a1,b1,t;
    bool flag1=true,flag2=false;
    cin>>n;
    long long int x[n],y[n],k[n];
    int a2[32],b2[32];
    vector<long long int> v;
    for(int i=0;i<n;i++){
        cin>>x[i];
        cin>>y[i];
        k[i]=(x[i]+y[i]+10000000000)%2;
    }

    t=1;
    for(int i=0;i<32;i++){
        v.push_back(t);
        t*=2;
    }

    for(int i=1;i<n;i++){
        if(k[0]!=k[i])flag1=false;
    }

    if(k[0]==0){
        flag2=true;
    }

    if(flag1){
        if(flag2){
            v.push_back(1);
            for(int i=0;i<n;i++){
                x[i]--;
            }
        }
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i==v.size())cout<<endl;
            else cout<<" ";
        }
        for(int i=0;i<n;i++){
            a=x[i]+y[i];
            b=x[i]-y[i];
            a1=(v[31]*2-1-a)/2;
            b1=(v[31]*2-1-b)/2;
            for(int j=0;j<32;j++){
                a2[j]=a1%2;
                a1=a1/2;
                b2[j]=b1%2;
                b1=b1/2;
            }
            for(int i=0;i<32;i++){
                if(a2[i]==0&&b2[i]==0)cout<<"R";
                if(a2[i]==1&&b2[i]==1)cout<<"L";
                if(a2[i]==1&&b2[i]==0)cout<<"D";
                if(a2[i]==0&&b2[i]==1)cout<<"U";
            }
            if(flag2)cout<<"R";
            cout<<endl;
        }
        
    }
    else{
        cout<<-1<<endl;
    }
}