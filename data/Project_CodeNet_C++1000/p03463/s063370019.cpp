#include <bits/stdc++.h>
using namespace std;

int main(){
int a,x,y;
  cin >> a >> x >> y;
int dist=y-x-1;  
if(dist%2==0)cout << "Borys" << endl;
else cout << "Alice" << endl;
}