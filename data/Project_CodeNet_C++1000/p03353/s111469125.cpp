#include <bits/stdc++.h>
using namespace std;


int main() {

string s;
long K;
cin>>s>>K;
set<string> d;
int n=s.size();

for(int i=1;i<=K;i++){
  for(int j=0;j<n-i+1;j++){
    d.insert(s.substr(j,i));
  }
}

auto itr = d.begin();
for(int i=0;i<K-1;i++) itr++;
cout<<*itr<<endl;

}
