//https://atcoder.jp/contests/agc026/tasks/agc026_b
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		int64_t a,b,c,d;std::cin>>a>>b>>c>>d;

		// after each day, the num of cans:
		// * if > c+b:   -= b (still > c),
		// * else (but still >= b): += d-b. (after that it's >= d)
		if(a>c+b)
			a=(a-c-1)%b+c+1;

		if(d>c+b)
			// after each +d-b, the next day it's always -b
			// while(d>c+b) d-=b;
			d=(d-c-1)%b +c+1;

		if(d<b||a<b){
NO:
			std::cout<<"No\n";
			continue;
		}

		if(c+1>=b){
YES:
			std::cout<<"Yes\n";
			continue;
		}

		// now c+1<b<=d, b<=a, a<=c+b, d<=c+b.
		// after the first jump d will be added
		if(b==d)goto YES;

		// before each +d-b op, the num of fruit is in ] c .. b+c ] (#=b)
		auto min_a=(a-c-1)%std::__gcd(b,d) +c+1;
		if(min_a<b)goto NO;else goto YES;
	}
}