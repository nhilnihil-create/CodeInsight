#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

string a;
int sum=9999999;

int main() {
    cin>>a;
    for(int i=1; i<a.size(); i++) {
        if(a[i]!=a[i-1]) {
            sum=min(sum,max(i,int(a.size())-i));
        }
    }
    cout<<min(sum,int(a.size()))<<endl;
    return 0;
}