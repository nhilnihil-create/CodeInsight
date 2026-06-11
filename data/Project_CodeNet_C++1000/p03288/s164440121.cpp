#include <bits/stdc++.h>
using namespace std;
int main(void){
   int R;
   cin >> R;
   if(R<2800 && 1200<=R) cout << "ARC" << endl;
   else if(R<1200) cout << "ABC" << endl;
   else cout << "AGC" << endl;
}
