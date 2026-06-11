#include<bits/stdc++.h>

#define swap(type,a,b) {type t; t=a; a=b; b=t;}
#define forN(i,n) for(int i=0;i<n;i++)
#define forS(i,start,n) for(int i=start;i<n;i++)
#define ll long long
#define pb(t,d,n) {t p;int i;forN(i,n){cin>>p;d.push_back(p);}}
#define DOUBLE fixed << setprecision(15)
#define c2i(c) {i-48;}
#define i2c(n) {n+48;}

using namespace std;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;

string next3(string s){
    int tmp=1;
    forN(i,s.size()&&tmp==1){
        s[i]+=tmp;
        if(s[i]>'2') s[i]='0';
        else if(s[i]<='2') tmp=0;
    }
    if(tmp==1) s.push_back('0');
    return s;
}
bool is753(string s){
    int tmp=0;
    forN(i,s.size()){
        tmp|=(1<<(s[i]-48));
    }
    return tmp==7;
}
string d2t753(int n){
    char data[]="0001122333";
    char dt[]="00010101000";
    int log10n = log10(n)+1;
    string s(log10n,'0');
    int t=0;
    forN(i,log10n){
        int tmp=n/(int)pow(10,i)%10;
        if(tmp==0) t++;
        else{
            for(;t>0&&dt[tmp]=='0';t--){
                n-=(int)pow(10,t-1);
            }
            break;
        }
    }
    forN(i,log10n){
        s[i]=data[n/(int)pow(10,i)%10];
    }
    forN(i,log10n-1){
        if(s[i]<='0'){
            s[i+1]--;
            s[i]='2';
        }else s[i]--;
    }
    s[s.size()-1]--;
    return s;
}
bool leftBig(string a,string b){
    if(a.size()>b.size()) return true;
    else if(a.size()<b.size()) return false;
    else{
        reverse(b.begin(),b.end());
        if(a.compare(b)>=0) return true;
        else return false;
    }
}

int main(){
    int m,n,cnt=0;
    string s;

    vector<string> db,db2;
    cin>>n;
    string res=d2t753(n);
    reverse(res.begin(),res.end());
    string i = "210";
    if(!leftBig(res,i)){
        cout<<0<<endl;
    }else{
        do{
            db2.push_back(i);
            if(is753(i)) { cnt++; db.push_back(i); }
        }while(leftBig(res,i=next3(i)));
        cout << cnt << endl;
    }
}
