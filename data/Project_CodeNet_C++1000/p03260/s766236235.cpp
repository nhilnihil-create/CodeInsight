#include <bits/stdc++.h>
#include <string>
using namespace std;
void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main() {
    init();
int a,b;
cin>>a>>b;
if(a==1&&b==3||a==3&&b==1){
    cout<<"Yes";
}
else if(a==3&&b==3||b==3&&a==3) {   cout<<"Yes";
}
else if(a==1&&b==1){cout<<"Yes";
}
else
    cout<<"No";
}
