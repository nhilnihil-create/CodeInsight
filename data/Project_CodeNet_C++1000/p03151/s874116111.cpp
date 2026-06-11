#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdio>

#include<vector>
using namespace std;
int a[233333];  //A数组
int b[233333];  //B数组
long long ans;  //注意开ll！
vector<int> v;
int sum;
int main(){
    int n;
    cin>>n;
    sum=n;
    for(int i=0;i<n;i++){//读入
        cin>>a[i];
    }
    for(int i=0;i<n;i++){//读入
        cin>>b[i];
    }
    bool flag=true;
    for(int i=0;i<n;i++){
        ans+=a[i]-b[i];//算贡献值
        if(a[i]>=b[i]){//如果贡献值非负
            v.push_back(a[i]-b[i]);//压入贡献值
        }
        else{
            flag=false;
        }
    }
    if(flag){//如果所有人都是非负贡献值
        puts("0");//不需要改变
        return 0;
    }
    sort(v.begin(),v.end());
    if(ans>=0){
        for(int i=0;i<v.size();i++){
            if(ans>=v[i]){//返还贡献值
                ans-=v[i];
                sum--;//计算答案
            }
            else{
                break;
            }
        }
        cout<<sum<<endl;//输出
    }
    else{
        puts("-1");
    }
    return 0;
}