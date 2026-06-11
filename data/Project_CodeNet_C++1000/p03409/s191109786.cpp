#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int,int>> a(n,pair<int,int> (0,0));
  for(int i=0;i<n;i++) {
    int x,y;
    cin >> x >> y;
    a.at(i)=pair<int,int> (x,y);
  }
  vector<pair<int,int>> b(n,pair<int,int> (0,0));
  for(int i=0;i<n;i++) {
    int x,y;
    cin >> x >> y;
    b.at(i)=pair<int,int> (x,y);
  }
  sort(a.rbegin(),a.rend());
  sort(b.begin(),b.end());
  int count=0;
  for(int i=0;i<n;i++){
    int temp_y=-1;
    int temp_id=-1;
    for(int j=0;j<a.size();j++) {
      if(a.at(j).first<b.at(i).first
      &&a.at(j).second<b.at(i).second) {
        if(temp_y<a.at(j).second) {
          temp_y=a.at(j).second;
          temp_id=j;
        }
      }
    }
    if(temp_id!=-1) {
      count++;
      a.erase(a.begin()+temp_id);
    }
  }
  cout << count << endl;
}