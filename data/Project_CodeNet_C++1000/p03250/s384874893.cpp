#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

int arr[3];

cin >> arr[0] >> arr[1] >> arr[2];

sort(arr, arr+3);

cout << (arr[2]*10)+(arr[1])+arr[0] << endl ;

 	return 0;
}










