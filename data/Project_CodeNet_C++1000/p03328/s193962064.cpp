#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    
    int hoge=b-a;
    int fuga=hoge*(hoge+1)/2;
    
    cout<<fuga-b<<endl;
    
    return 0;
}