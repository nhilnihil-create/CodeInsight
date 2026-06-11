#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 0;
  int left = 0;
  while(left<n){
    int sum = 0;
    int right = left;
    int nleft = 0;
    int cnt = 0, mcnt=0;
    if(s[left]=='0') cnt++;
    while(right < n && cnt<=k){
      sum++;
      if(nleft==0&&cnt>0&&s[right]=='1'){
        nleft = right;
        mcnt = right - left;
      }
      if(s[right]=='1'&& s[right+1]=='0') cnt++;
      right++;
    }
    ans = max(sum, ans);
    if(right>=n-1){
      break;
    }
    if(nleft>0){
      left = nleft;
    }else{
      left++;
    }
  }
  cout << ans << endl;
  return 0;
}
