#include<bits/stdc++.h> 

int main() 
{
	int n, a, b; 
	std::cin >> n >> a >> b; 
	std::cout << (((b - a) & 1) ? "Borys\n" : "Alice\n"); 
	return 0;
}
