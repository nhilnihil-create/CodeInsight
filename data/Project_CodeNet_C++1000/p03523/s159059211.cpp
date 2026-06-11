#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >>s;
  vector<string>t(16);
  t[0]="KIHBR";
  t[1]="KIHBRA";
  t[2]="KIHBAR";
  t[3]="KIHBARA";
  t[4]="KIHABR";
  t[5]="KIHABRA";
  t[6]="KIHABAR";
  t[7]="KIHABARA";
  t[8]="AKIHBR";
  t[9]="AKIHBRA";
  t[10]="AKIHBAR";
  t[11]="AKIHBARA";
  t[12]="AKIHABR";
  t[13]="AKIHABRA";
  t[14]="AKIHABAR";
  t[15]="AKIHABARA";
  for(int i=0;i<16;i++){
    if(s==t[i]){
      cout<<"YES"<<endl;
      return 0;
    }
  }cout<<"NO"<<endl;
  return 0;
}

  