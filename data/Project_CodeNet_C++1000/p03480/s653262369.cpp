#include<bits/stdc++.h>
#define WR "txt"

void Open() { freopen(WR".in", "r", stdin); freopen(WR".out", "w", stdout); }
void Close() { fclose(stdin); fclose(stdout); }
using namespace std;
int Read()  {
	int val = 0, opt = 1; char ch;
	while (!isdigit(ch = getchar() )) if (ch == '-') opt = -1;
	while (isdigit( ch )) (val *= 10) += ch - '0', ch= getchar();
	return val * opt;
}

char s[100100];
int Ans;

void work()  {
	scanf("%s", s + 1);
	char ch;
	int l = strlen(s + 1);
	Ans = l / 2;
	if (l % 2)  {
		ch = s[l / 2 + 1];
		for (int i = 0;i <= l / 2; i++)  {
			if (s[l / 2 - i + 1] == s[l / 2 + i + 1] && s[l / 2 - i + 1] == ch) Ans++;
			else {
				break;
			}
		}
		printf("%d\n", Ans);
		return ;
	}
	ch = s[l / 2];
	for (int i = 1;i <= l / 2; i++)  
		if (s[l / 2 - i + 1] == s[l / 2 + i] && s[l / 2 - i + 1] == ch) Ans++;
		else  {
			break;
		}
	printf("%d\n", Ans);
}

int main(void)  {
	//Open();
	work();
	//Close();
	return 0;
}