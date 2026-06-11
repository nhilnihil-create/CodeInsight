#include <iostream>
#include <string>

void aaa(int *a,int start,int end){
  if(start<end){
	for(int i=start;i<end; i++){
      if(a[i]>a[i+1]){
        int tmp=a[i];
        a[i]=a[i+1];
        a[i+1]=tmp;
      }
    }
    aaa(a,start,end-1);
  }
}

int main(void){
  using namespace std;

  int n,m,count[101];
  string s[101],t[101];
  
  cin >> n;
  for(int i=0;i<n;i++){
    std::cin >> s[i];
  }
  cin >> m;
  for(int i=0;i<m;i++){
    std::cin >> t[i];
  }
  s[n]="";
  
  for(int i=0;i<n+1;i++){
    count[i]=0;
    for(int j=0;j<n;j++){
      if(s[i]==s[j]) count[i]++;
    }
    for(int k=0;k<m;k++){
      if(s[i]==t[k]) count[i]--;
    }
  }
  
  aaa(count,0,n);
  std::cout << count[n] <<endl;
}

  