#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int as=0,bs=0,abg=0,reg=0;
  for(int i=0;i<n;i++){
    string a;
    cin >> a;
    int q=a.size();
    for(int w=0;w<q-1;w++){if(a[w] == 'A' && a[w+1] == 'B'){reg++;}}
      if(a[0] == 'B' && a[q-1] == 'A'){abg++;
                                    continue;}
      if(a[q-1] == 'A'){as++;}
    if(a[0] == 'B'){bs++;}
  }
 if(abg == 0){cout << min(as,bs)+reg << endl;}
  else{if(as+bs>0){cout << abg + min(as,bs)+reg << endl;}else{cout << abg-1+reg << endl;}}
}
