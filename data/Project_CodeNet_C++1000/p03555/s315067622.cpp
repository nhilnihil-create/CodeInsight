/***
*	author  :_shamim
*	created : 05.05.2020
*
***/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <list>
#include <set>
#include <queue>
#include <iterator>
#include <bitset>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll             long long
#define _              ios_base::sync_with_stdio(0);cin.tie(0);
#define loop           for(i=0;i<n;i++)
#define pb             push_back
#define tc()           int t;cin>>t;while(t--)          

using namespace std;

ll i,j,temp;

int main()
{_
	
	char name1[4];
	char name2[4];
	char name3[4],x;
	int flag=0;

	cin>>name1>>name2;

	for(i=0,j=2;i<3;i++,j--){
		if(name1[i]!=name2[j]){
			flag = 0;
			break;
		}
		else{
			flag = 1;
		}

	}
	if(flag){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}