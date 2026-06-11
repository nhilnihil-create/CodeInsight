#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int time=100*(n-m)+1900*m;
    int two=1;
    for(int i=0;i<m;i++)two*=2;
    cout << time*two;
}