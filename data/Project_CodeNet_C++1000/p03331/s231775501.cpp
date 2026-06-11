#include <iostream>

int main(){
	int n;
	int q1, q2, r1, r2;
	int s;
	int cand;
	std::cin >> n;

	for(int x = 1; x <= n - 1; ++x){
		int y = n - x;
		s = 0;
		//use do-while sentence
		q1 = x;
		do{
			r1 = q1 % 10;	
			q1 = q1 / 10;
			s += r1;
		}while(q1 != 0);

		q2 = y;
		do{
			r2 = q2 % 10;
			q2 = q2 / 10;
			s += r2;
		}while(q2 != 0);
		
		//std::cout << x << " " << y << " " << s << std::endl;

		if(s < cand || x == 1){
			cand = s;
		}
	}

	std::cout << cand << std::endl;

	return 0;
}
