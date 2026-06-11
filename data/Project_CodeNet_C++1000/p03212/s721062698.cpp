#include <bits/stdc++.h>
using namespace std;

using LL = long long;

// ABC 114 C
// DFS 

// HOW TO DO 
// 1. input 
//    int N 
//    
// 2. 全探索：もし３、５、７全てが含まれてたら ans++
//    a: 3 が含まれていたら１
//    b: 5 が含まれていたら１
//    c: 7 が含まれていたら１
//    3-> 5-> 7-> の順に*１０で桁増やす

//    ex) 575 
//    x: 3353 a: 1 b:  1 c:  0
//    x: 0 a: 0 b:  0 c:  0
//    x: 3 a: 1 b:  0 c:  0
//    x: 33 a: 1 b:  0 c:  0
//    x: 333 a: 1 b:  0 c:  0
//    x: 3333 a: 1 b:  0 c:  0 -> return 
//    x: 3335 a: 1 b:  1 c:  0 -> return
//    x: 3337 a: 1 b:  0 c:  1 -> return
//    x: 335 a: 1 b:  1 c:  0
//    x: 3353 a: 1 b:  1 c:  0 -> return
//    x: 3355 a: 1 b:  1 c:  0 -> return
//    x: 3357 a: 1 b:  1 c:  1 -> return
//    x: 337 a: 1 b:  0 c:  1
//    x: 3373 a: 1 b:  0 c:  1 -> return
//    x: 3375 a: 1 b:  1 c:  1 -> return
//    x: 3377 a: 1 b:  0 c:  1 -> return
//    x: 35 a: 1 b:  1 c:  0
//    x: 353 a: 1 b:  1 c:  0
//    x: 3533 a: 1 b:  1 c:  0 -> return
//    x: 3535 a: 1 b:  1 c:  0 -> return
//    x: 3537 a: 1 b:  1 c:  1 -> return
//    x: 355 a: 1 b:  1 c:  0
//    x: 3553 a: 1 b:  1 c:  0 -> return
//    x: 3555 a: 1 b:  1 c:  0 -> return
//    x: 3557 a: 1 b:  1 c:  1 -> return
//    x: 357 a: 1 b:  1 c:  1 -----------> ans ++ 
//    x: 3573 a: 1 b:  1 c:  1 -> return
//    x: 3575 a: 1 b:  1 c:  1 -> return
//    x: 3577 a: 1 b:  1 c:  1 -> return
//    x: 37 a: 1 b:  0 c:  1
//    x: 373 a: 1 b:  0 c:  1
//    x: 3733 a: 1 b:  0 c:  1 -> return
//    x: 3735 a: 1 b:  1 c:  1 -> return
//    x: 3737 a: 1 b:  0 c:  1 -> return
//    x: 375 a: 1 b:  1 c:  1 -----------> ans ++ 
\
// 3.  output ans


LL n,ans=0;

void dfs(LL x,LL a,LL b,LL c){ 
  if(x>n) return ;
  if(a&&b&&c) ans++;
  dfs(x*10+3,1,b,c);
  dfs(x*10+5,a,1,c);
  dfs(x*10+7,a,b,1);
  
}
signed main(){
  // input 
  cin>>n;

  // find 753
  dfs(0,0,0,0);

  // output 
  cout<<ans<<endl;
  return 0;
}
