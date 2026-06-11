#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


signed main() {
  std::string s;
  int x,y,r=0,v=0,c=0,ff=0,gg=0,ss,sc;
  std::vector<int> f,g;
  std::cin >> s >> x >> y;
  ss=s.length();
  for(int i;i<ss;i++){
    c++;
    if(s[i]=='F'){
      x--;
    } else {
      break;
    }
  }
  sc=ss-c;
  if(sc){
  } else {
    if(x==0){
      if(y==0){
        puts("Yes");
        return 0;
      }
    }
    puts("No");
    return 0;
  }
  for(int i;i<sc;i++){
    if(s[i+c]=='F'){
      r++;
    } else {
      if(v){
        if(r){
          f.push_back(r);
          ff++;
        }
        v=1-v;
      } else {
        if(r){
          g.push_back(r);
          gg++;
        }
        v=1-v;
      }
      r=0;
    }
  }
  if (r) {
    if(v){
      f.push_back(r);
      ff++;
    } else {
      g.push_back(r);
      gg++;
    }
  }
  sort(f.rbegin(),f.rend());
  sort(g.rbegin(),g.rend());
  for(int i;i<ff;i++){
    if(x>0){
      x-=f[i];
    } else {
      x+=f[i];
    }
  }
  for(int i;i<gg;i++){
    if(y>0){
      y-=g[i];
    } else {
      y+=g[i];
    }
  }
  if(x==0){
    if(y==0){
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}