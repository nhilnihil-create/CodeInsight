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
    ABC92();
}

void ABC92(){
    int n,d,x,i,j,ans=0;
    cin>>n>>d>>x;
    vector<int> vec(n);
    for(i=0;i<n;i++){
        cin>>vec[i];
    }
    for(i=0;i<d;i++){
        for(j=0;j<n;j++){
            if(i%vec[j]==0)ans++;
        }
    }
    cout<<ans+x<<endl;
}