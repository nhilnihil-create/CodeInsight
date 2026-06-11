#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	char S[50];
	scanf("%s", S);
	int len = strlen(S);
	
	char *A="AKIHABARA";
	char *B="KIHABARA";
	char *C="AKIHBARA";
	char *D="AKIHABRA";
	char *E="AKIHABAR";
	char *F="KIHBARA";
	char *G="AKIHBRA";
	char *H="AKIHABR";
	char *I="AKIHBR";
	char *J="KIHABR";
	char *K="KIHBAR";
	char *L="KIHBRA";
	char *M="KIHBR";
	char *N="KIHABRA";
	char *O="AKIHBAR";
	char *P="KIHABAR";
	
	if(len>=10) printf("NO");
	else{
		if( strncmp(S,A,9)==0 || strncmp(S,B,8)==0 || strncmp(S,C,8)==0 || strncmp(S,D,8)==0 || strncmp(S,E,8)==0 || strncmp(S,F,7)==0 || strncmp(S,G,7)==0 || strncmp(S,H,7)==0 || strncmp(S,I,6)==0 || strncmp(S,J,6)==0 || strncmp(S,K,6)==0 || strncmp(S,L,6)==0 || strncmp(S,M,5)==0 ||  strncmp(S,N,7)==0 || strncmp(S,O,7)==0 || strncmp(S,P,7)==0) printf("YES");
		else printf("NO");
	}
	return 0;
	
}