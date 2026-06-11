#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
int main(){
    string st;
    cin>>st;
    if(st.substr(0,3)!="2018")st.replace(0,4,"2018");
    cout<<st<<endl;
}