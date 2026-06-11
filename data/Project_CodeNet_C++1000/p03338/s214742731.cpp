#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC90(void);
void ABC91(void);
void ABC92(void);
void ABC93(void);
void ABC94(void);
void ABC95(void);
void ABC96(void);
void ABC97(void);
void ABC98(void);
void ABC99(void);

int main(void){
    ABC98();
}

void ABC98(){
    int n,i,j,c=0,max=0;
    string s;
    char cha='\0';
    cin>>n>>s;
    for(i=1;i<n;i++){
        string a=s.substr(0,i);
        string b=s.substr(i,n);
        sort(a.begin(),a.end());
        for(j=0;j<a.size();j++){
            if(a[j]!=cha){
                cha=a[j];
                if(count(b.begin(),b.end(),cha)>=1)c++;
            }
        }
        if(c>max)max=c;
        c=0;
        cha='\0';
    }
    cout<<max<<endl;
}