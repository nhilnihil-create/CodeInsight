#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b,c,d,e=0;
    string s;
    cin>>n>>a>>b>>c>>d>>s;
    b--;
    a--;
    int a1=a,b1=b;
    for(int i=b;i<d;i++){
        if(b<d-1){
            if(s[b+1]=='.' && b+1!=a)
                b++;
            else if(s[b+2]=='.' && b+2!=a)
                b+=2;
        }
        if(s[b-1]=='.' && s[b+1]=='.'){
            e=1;
        }
    }
    for(int i=a;i<c;i++){
        if(a<c-1){
            if(e==0){
                if(s[a+1]=='.' && a+1!=b)
                    a++;
                else if(s[a+2]=='.' && a+2!=b)
                    a+=2;
            } 
            else{
                if(s[a+1]=='.')
                    a++;
                else if(s[a+2]=='.')
                    a+=2;
            } 
        }
    }
    if(a==c-1 && b==d-1){
        cout<<"Yes"<<endl;
        return(0);
    }
    e=0;
    for(int i=a1;i<c;i++){
        if(a1<c-1){
            if(s[a1+1]=='.'&& a1+1!=b1)
                a1++;
            else if(s[a1+2]=='.'&& a1+2!=b1)
                a1+=2;
        }
        if(s[a1-1]=='.' && s[a1+1]=='.'){
            e=1;
        }
    }
    for(int i=b1;i<d;i++){
        if(b1<d-1){
            if(e==0){
                if(s[b1+1]=='.' && b1+1!=a1)
                    b1++;
                else if(s[b1+2]=='.' && b1+2!=a1)
                    b1+=2;
            }
            else{
                if(s[b1+1]=='.')
                    b1++;
                else if(s[b1+2]=='.')
                    b1+=2;
            } 
        }
    }
    if(a1==c-1 && b1==d-1){
        cout<<"Yes"<<endl;
        return(0);
    }
    cout<<"No"<<endl;
    return(0);
}