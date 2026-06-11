#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n); i++)
using namespace std;

int main() {
 int a,b;
cin >> a >> b;
int kura = max(a,b);
int tugi = max(a,b) -1;
if(kura + tugi >= a+b){
  cout << kura + tugi << endl;
}
else{
  cout << a+b << endl;
}

}