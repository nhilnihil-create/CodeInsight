#include <bits/stdc++.h>
using namespace std;



int main() {

	int a,b;
    cin>>a>>b;

    string s;
    cin>>s;

    bool flg=true;

    for(int i=0;i<s.size();i++){
        if(i==a){
            if(s.at(i)!='-')
                flg=false;
        }
        else if(s.at(i)<'0'||s.at(i)>'9')
            flg=false;
    }

    if(flg)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

	return 0;
}