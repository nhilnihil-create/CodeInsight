#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

int n;
cin >> n;
int arr[n];

for(int i=0;i<n;i++)
{
	cin >> arr[i];
}

int max=0;
int sum=0;

for(int i=0;i<n;i++)
{
	if(arr[i]>max)
	{
		max=arr[i];
	}
	sum=sum+arr[i];
}

cout << (sum)-(max/2) << endl;


 	return 0;
}










