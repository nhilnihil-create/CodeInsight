#include <bits/stdc++.h>
using namespace std;
 

 
int main() {


    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;


    //垂直ベクトル
    int xv=-(y2-y1);
    int yv=x2-x1;

    cout<<x2+xv<<' '<<y2+yv<<' '<<x1+xv<<' '<<y1+yv<<endl;


 	return 0;
}
