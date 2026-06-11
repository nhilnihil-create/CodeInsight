#include <bits/stdc++.h>
#include <math.h>
int n,i,j,k,count1=0,count2=0;
using namespace std;
void ABC110(void);
void ABC111(void);
void ABC112(void);
void ABC113(void);
void ABC114(void);
void ABC115(void);
void ABC116(void);
void ABC117(void);
void ABC118(void);
void ABC119(void);

int main(void){
    ABC117();
}

void ABC117(){
    int sum=0;
    cin>>n;
    vector<int> vec(n);
    for(i=0;i<n;i++){
        cin>>vec[i];
        sum+=vec[i];
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    if(vec[0]<(sum-vec[0]))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}