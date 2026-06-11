 #include <stdio.h>
 
 int main(){
 	
 	int AB, BC, CA, area;
 	scanf("%d %d %d", &AB, &BC, &CA);
 	
 	if(AB > BC && AB > CA){
 	area = 0.5*(BC*CA);
 	printf("%d", area);
	 }
 	
 	if(BC > AB && BC > CA){
 	area = 0.5*(AB*CA);
 	printf("%d", area);
	 }
	 
	if(CA > AB && CA > BC){
 	area = 0.5*(AB*BC);
 	printf("%d", area);
	 }
 	
 	return 0;
 }