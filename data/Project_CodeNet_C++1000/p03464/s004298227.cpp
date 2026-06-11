#include<bits/stdc++.h>
using namespace std;
int main(){
 int K;
  cin>>K;
  vector<int64_t>A(K);
  for(int i=0;i<K;i++)
    cin>>A.at(i);
  int64_t left=1; int64_t right=1000000000000000000;
    while(1<right-left){
    int64_t mid=left+(right-left)/2;
      int64_t n=mid;
      for(int i=0;i<K;i++)
        n=(n/A.at(i))*A.at(i);
      if(2<=n)
        right=mid;
      else
        left=mid;
    }int64_t left1=1; int64_t right1=1000000000000000000;
    while(1<right1-left1){
    int64_t mid=left1+(right1-left1)/2;
      int64_t n=mid;
      for(int i=0;i<K;i++)
        n=(n/A.at(i))*A.at(i);
      if(3<=n)
        right1=mid;
      else
        left1=mid;
    }
  if(left1<right)
    cout<<-1<<endl;
    else
      cout<<right<<" "<<left1<<endl;
    return 0;
}
