#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <utility> 

int main()
{
	int M, N;
    std::cin >> M >> N;
    
	std::map<int, std::map<int, int>> ken_shi_y;
	for(int i=0; i<N; i++)
    {
    	int P, Y;
    	std::cin >> P>> Y;
		ken_shi_y[P][Y] = i;
    }
  		
  	std::vector<std::pair<int,int>> result(N);
  	for(const auto& ken : ken_shi_y)
    {
      int c=1;
      for(const auto& e : ken.second)
      {
 		result[e.second] = std::pair<int,int>(ken.first, c);
        c++;
      }
    }
  
  	for(const auto& e : result)
    {
		std::cout.fill('0');
		std::cout.width(6);      
	    std::cout << e.first;
		std::cout.fill('0');
		std::cout.width(6);      
      	std::cout << e.second << std::endl;
    }
  
	return 0;
}
