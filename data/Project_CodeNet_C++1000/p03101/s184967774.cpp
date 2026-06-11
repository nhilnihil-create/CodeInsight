#include <bits/stdc++.h>
#include <vector>


using namespace std;
int main(){


 int R,C,r,c;
 cin>>R>>C;
 cin>>r>>c;

 int ans = R*C - (r*C + (c*R-c*r));
 cout<<ans<<endl;


return 0;
}




