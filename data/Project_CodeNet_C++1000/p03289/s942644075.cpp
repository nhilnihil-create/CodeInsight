#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC100(void);
void ABC101(void);
void ABC102(void);
void ABC103(void);
void ABC104(void);
void ABC105(void);
void ABC106(void);
void ABC107(void);
void ABC108(void);
void ABC109(void);

int main(void){
    ABC104();
}

void ABC104(){
    int i,c=0,d=0;
    string s;
    cin>>s;
    if(s[0]=='A')c++;
    for(i=1;i<s.length();i++){
        if(s[i]=='C'&&i>=2&&i<=s.length()-2){
            c++;
            d++;
        }
        if(s[i]>='a'&&s[i]<='z'&&i>=1)c++;
    }
    cerr<<c<<endl;
    if(c==s.length()&&d==1)cout<<"AC"<<endl;
    else cout<<"WA"<<endl;
}