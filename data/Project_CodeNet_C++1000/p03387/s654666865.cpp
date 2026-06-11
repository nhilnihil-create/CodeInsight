#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
int main(){
    int a,b,c;cin>>a>>b>>c;
    int sum=a+b+c;
    int count=0;
    int tmp=max(a,b);
    int Max=max(tmp,c);
    while(sum%3!=0||sum/3<Max){
        sum+=2;
        count++;
    }
    cout<<count<<endl;
    

}