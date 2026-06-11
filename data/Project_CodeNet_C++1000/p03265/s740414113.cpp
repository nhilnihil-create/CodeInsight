#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int x3,y3,x4,y4;
    x4=x1-(y2-y1);
    y4=y1+(x2-x1);
    x3=x1+(x2-x1)+(x4-x1);
    y3=y1+(y2-y1)+(y4-y1);
    cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
    
}
