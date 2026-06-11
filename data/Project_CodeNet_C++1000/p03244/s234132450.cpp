#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
vector<vector<int>> graph;

bool sort_sec(const pair<int,int> &a,const pair<int,int> &b){
   if(a.second<b.second){
      return true;
   }
   return false;
}

void swap(int *a,int *b){
   int temp=*a;
   *a=*b;
   *b=temp;
}

int main(void){
   int N;
   cin>>N;
   vector<int> a(N);
   for(int i=0;i<N;i++){
      cin>>a[i];
   }
   set<int> s;
   map<int,int> mp1,mp2;
   for(int i=0;i<N;i++){
      if(i%2==0) mp1[a[i]]++;
      else mp2[a[i]]++;
      s.insert(a[i]);
   }
   if(s.size()==1){
      cout<<N/2<<endl;
      return 0;
   }
   vector<pair<int,int>> odd,even;
   for(auto x:mp1){
      odd.push_back({x.first,x.second});
   }
   for(auto y:mp2){
      even.push_back({y.first,y.second});
   }
   sort(odd.begin(),odd.end(),sort_sec);
   sort(even.begin(),even.end(),sort_sec);
   int X=odd.size();
   int Y=even.size();
   if(odd[X-1].first!=even[Y-1].first){
      cout<<N-odd[X-1].second-even[Y-1].second<<endl;
   }else{
      int result1=N-odd[X-1].second-even[Y-2].second;
      int result2=N-odd[X-2].second-even[Y-1].second;
      cout<<min(result1,result2)<<endl;
   }
   return 0;
}
