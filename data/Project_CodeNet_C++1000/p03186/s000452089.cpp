#include <bits/stdc++.h>
using namespace std;
 

    using Graph = vector<vector<int>>;
 
int main() {

    int a,b,c;
    cin>>a>>b>>c;



    if(c<=a)
        cout<<c+b<<endl;
    else{//c>a
        if(c-a<=b){
            cout<<c+b<<endl;
        }
        else{//c-a>b
            cout<<b*2+a+1<<endl;
        }
    }

 	return 0;
}