#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
long a,b,c,d=0;
  cin>>a>>b>>c>>d;
      if(abs(a-c)<=d||(abs(a-b)<=d&&abs(b-c)<=d))	cout<< "Yes" <<endl;
        else cout<< "No" <<endl;
}
