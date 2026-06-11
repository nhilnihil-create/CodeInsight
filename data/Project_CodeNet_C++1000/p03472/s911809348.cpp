#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;

struct swords{
	LLI dmg;
	int type;
};

bool check(swords x, swords y)
{
	return (x.dmg < y.dmg);
}

LLI solution(swords arr[], int n, LLI h)
{
	int i = n-1;
	LLI sum = 0;
	sort(arr,arr+n,check);
	
	while( h > 0 )
	{
		if( arr[i].type == 1 ){
			h -= arr[i].dmg;
			sum++;
		}else{
			sum += h/arr[i].dmg;
			if( h % arr[i].dmg != 0 )
				sum++;
			break;
		}
		i--;
	}
	return sum;
}

int main()
{
	int n;
	LLI h;
	cin >> n >> h;
	
	LLI a, b;
	swords arr[2*n];
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		
		arr[2*i].dmg = a;
		arr[2*i].type = 0;
		
		arr[2*i+1].dmg = b;
		arr[2*i+1].type = 1;
	}
	cout << solution(arr,2*n,h);
}