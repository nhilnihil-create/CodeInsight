#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void){
    string s;
    int n,x,y,f=0,p=0;
    map<int, bool> a,b,c;
    cin>>s>>x>>y;
    n=s.length();
    b[0]=true;
    for(int i=0;i<n;i++){
        if(s[i]=='F'){
            f++;
        }
        if(s[i]=='T'||i==n-1){
            if(p==0){
                a[f]=true;
                p=1;
            }else if(p==1&&f!=0){
                c=map<int, bool>();
                for(auto u=a.begin();u!=a.end();u++){
                    if(u->second==true){
                        c[u->first+f]=c[u->first-f]=true;
                    }
                }
                a=c;
            }else if(f!=0){
                c=map<int, bool>();
                for(auto u=b.begin();u!=b.end();u++){
                    if(u->second==true){
                        c[u->first+f]=c[u->first-f]=true;
                    }
                }
                b=c;
            }
            p=3-p;
            f=0;
            
        }
    }
    if(a[x]&&b[y]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
