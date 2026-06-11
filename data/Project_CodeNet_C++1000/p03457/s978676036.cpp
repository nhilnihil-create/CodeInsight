#include <iostream>
#include <cmath>

int main(){
  	int N;
  	int x = 0, y = 0;
  	int t = 0;
  	std::cin >> N;
  	int i;
  	for (i=0;i<N;i++){
      	int t_new, x_new, y_new;
      	std::cin >> t_new >> x_new >> y_new;
      	int ds = abs(x-x_new) + abs(y-y_new);
        int dt = t_new-t;
      	if( ds > dt || ds%2 != dt%2) break; 
      	x = x_new;
      	y = y_new;
      	t = t_new;
    }
  	if(i == N) std::cout << "Yes" << std::endl;
  	else std::cout << "No" << std::endl;
}