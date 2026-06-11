#include <iostream>
#include <queue>

int main(){
   int K;
   std::cin >> K;

   const int n = 1000000;
   bool cache[n];
   for(int i=0; i<n; ++i)
      cache[i] = false;
   std::deque<std::pair<int,int> > dq;
   dq.push_front(std::make_pair(1,1));
   while(dq.size()){
      std::pair<int, int> cur = dq.front();
      dq.pop_front();
      if(cache[cur.first]) continue;
      cache[cur.first] = true;
      if(!cur.first){
	 std::cout << cur.second << std::endl;
	 return 0;
      }
      dq.push_front(std::make_pair(cur.first*10%K,cur.second));
      dq.push_back(std::make_pair((cur.first+1)%K,cur.second+1));
   }

   return -1;
}
