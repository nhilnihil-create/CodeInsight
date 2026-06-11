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
    ABC93();
}

void ABC93(){
    int a,b,k,i,j,x;
    cin>>a>>b>>k;
    vector<int> vec;
    for(i=0;i<k;i++){
        x=a+i;
        if(x<=b&&count(vec.begin(),vec.end(),x)==0)vec.push_back(x);
        x=b-i;
        if(x>=a&&count(vec.begin(),vec.end(),x)==0)vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    for(i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
}