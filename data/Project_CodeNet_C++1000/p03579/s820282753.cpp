#include<iostream>
#include<vector>
#define df 0
using namespace std;

int dfs(int v,int temp,int* color,vector<vector<int>> const& alist);

int main(){
  int n,m; cin >> n >> m;
  vector<vector<int>> alist(n);
  for(int i=0;i<m;i++){
    int a,b; cin >> a >> b;
    a--;b--;
    alist.at(a).push_back(b);
    alist.at(b).push_back(a);
  }
  int color[n]={};
  int s=dfs(0,1,color,alist);
  if(df)printf("%d\n",s);
  if(s==0){
    cout << (long int)n*(n-1)/2-m;
  }else{
    cout << (long int)s*(n-s)-m;
  }
}
int dfs(int v,int temp,int* color,vector<vector<int>> const& alist){
  if(df)printf("search %d\n",v);
  static int num1=0;
  static bool flag=true;
  if(!flag)return 0;
  temp*=-1;
  for(const int& u: alist.at(v)){
    if(color[u]==0){
      if(df)printf("%d colored by %d\n",u,temp);
      color[u]=temp;
      if(temp==1)num1++;
      dfs(u,temp,color,alist);
    }else if(color[u]!=temp){
      if(df)printf("NOT bipatite!!\n");
      flag=false;
      return 0;
    }
    if(!flag)return 0;
  }
  return num1;
}
