#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#define ll long long
using namespace std;
int main()
{
	int a,b,c,i,n;
	cin>>a>>b;
	cout<<100<<' '<<100<<endl;
	int j;
	for(i = 0;i < 50;i++){
        for(j = 0;j < 100;j++){
            if(i%2&&j%2&&a>1){
                cout<<'.';
                a--;
            }
            else{
                cout<<'#';
            }
        }
        cout<<endl;
	}
	for(i = 0;i < 50;i++){
        for(j = 0;j < 100;j++){
            if(i%2&&j%2&&b>1){
                cout<<'#';
                b--;
            }
            else{
                cout<<'.';
            }
        }
        cout<<endl;
	}
}