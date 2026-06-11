#include <iostream>
using namespace std;

int main()
{
	int paper_x, paper_y, max, min, N;
	cin >> N;
	cin >> paper_x;
	cin >> paper_y;
	if(paper_x <paper_y){
		max = paper_x;
	}else{
		max = paper_y;
	};
	if(paper_x + paper_y > N){
	min = paper_y -( N - paper_x );
}else{
	min = 0;
}
	cout << max << endl;
	cout << min;

	return 0;
}
