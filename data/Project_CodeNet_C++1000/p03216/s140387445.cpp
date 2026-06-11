#include<iostream>
#include<vector>
using namespace std;
typedef long int li;
#define df 0
int main(){
  int n,q;
  string str;
  cin >> n >> str >> q;
  vector<int>query(q);
  for(int i=0;i<q;i++){
    cin >> query.at(i);
  }

    li s=0;
    vector<li> d(n,0);
    for(int i=0;i<n;i++){
      // d();
      if(str.at(i)=='D')s++;
      d.at(i)=s;
    }
    if(df){
      for(int k=0;k<n;k++) printf("%d",d.at(k)%10);
      printf(":d\n");
    }
    s=0;
    vector<li> m(n,0);
    for(int i=0;i<n;i++){
      // d();
      if(str.at(i)=='M')s++;
      m.at(i)=s;
    }
    if(df){
      for(int k=0;k<n;k++) printf("%d",m.at(k)%10);
      printf(":m\n");
    }
    s=0;
    vector<li> dm(n,0);
    for(int i=0;i<n;i++){
      // dm();
      if(str.at(i)=='M')s+=d.at(i);
      dm.at(i)=s;
    }
    if(df){
      for(int k=0;k<n;k++) printf("%d",dm.at(k));
      printf(":dm\n");
    }

  for(int j=0;j<q;j++){
    s=0;
    for(int i=0;i<n;i++){
      if(str.at(i)=='C'){
	s+=dm.at(i);
	int q=query.at(j);
	if(i>=q){
	  s-=dm.at(i-q);
	  s-=d.at(i-q)*(m.at(i)-m.at(i-q));
	}
      }
    }
    cout << s << "\n";
  }

}