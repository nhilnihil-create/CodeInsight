#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool is_con(char S){
if (S =='A'||S =='G'||S =='C'||S =='T'){return true;}
return false;
}
int main() {
int cnt =0;
int MAX=0;
string S;
cin>>S;
for (int i = 0; i < S.size(); ++i)//スタートの決め方
{
	cnt = 0;
	if (is_con(S[i]))
	{
		cnt++;
		MAX=max(cnt,MAX);
		for (int j = i+1; j < S.size(); ++j)
		{
			if (is_con(S[j])){cnt++;MAX=max(cnt,MAX);}
			else break;
		}
	}
	else continue;	
}
cout<< MAX<<endl;
return 0;
}

